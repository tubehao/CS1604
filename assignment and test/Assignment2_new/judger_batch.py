import time
import random
import os
import subprocess
import argparse
import sys
import shutil
import tempfile

exec_name = {
    '1_cat': ['main.cpp', 'main'],
    '2_convert': ['main.cpp', 'main'],
    '3_sqrt': ['main.cpp', 'main'],
    '4_property': ['main.cpp', 'main'],
    '5_math': ['main.cpp', 'main'],
}
required = {
    '4_property': ['NumberProperty.cpp', 'NumberProperty.h'],
    '5_math': [
        'Sqrt.cpp', 'Sqrt.h', 'Convert2Int.cpp', 'Convert2Int.h',
        'NumberProperty.cpp', 'NumberProperty.h', 'MyMath.h'
    ]
}

# exec_name: {'task_name': ['main.cpp', 'executeable']}
input_name = ['1.in', '2.in', '3.in', '4.in', '5.in']
output_name = ['1.out', '2.out', '3.out', '4.out', '5.out']


def init_args():
    parser = argparse.ArgumentParser('Judger For Homework I')
    parser.add_argument(
        '-T', '--task', choices=list(exec_name.keys()),
        help='the task to judge'
    )
    parser.add_argument(
        '-I', '--input_dir', required=True,
        help='the path of input data file'
    )
    parser.add_argument(
        '-O', '--standard_dir', required=True,
        help='the path of standard output file'
    )
    parser.add_argument(
        '-S', '--source_dir', default='.',
        help='the folder containing the soruce code'
    )
    parser.add_argument(
        '--timeout', default=2, type=float,
        help='the timeout for judging (in seconds), default is 2'
    )

    args = parser.parse_args()
    return args


def get_random_filename():
    lst = []
    for x in range(10):
        lst.append(chr(ord('A') + random.randint(0, 25)))
    temp_path = ''.join(lst)
    return temp_path


def standard_judger(answer, std, max_score=10):
    # 忽略行末空格和文末空行
    with open(std) as Fin:
        c_std = Fin.read()
        c_std = c_std.rstrip().split('\n')
    with open(answer) as Fin:
        c_answer = Fin.read()
        c_answer = c_answer.rstrip().split('\n')
    if len(c_std) != len(c_answer):
        return 'File length differs', 0
    for idx, lin_std in enumerate(c_std):
        lin_ans = c_answer[idx].rstrip()
        lin_std = lin_std.rstrip()
        if lin_std != lin_ans:
            return f'Error is found at Line {idx}', 0
    return 'Correct', max_score


def judge(
    input_file, standard_file, exe, timeout,
    workdir, args, max_score=10, judger=standard_judger
):
    file_name = get_random_filename() + '.out'
    output_file = os.path.join(workdir, file_name)
    exec_file = os.path.join(workdir, exe)
    Fout = open(output_file, 'w')
    Fin = open(input_file)

    with Fin:
        with Fout:
            try:
                subprocess.run(
                    [exec_file], check=True, timeout=timeout,
                    stdin=Fin, stdout=Fout
                )
            except subprocess.TimeoutExpired:
                return 'Out of Time Limit!', 0
            except subprocess.CalledProcessError as e:
                return f'Runtime Error with returncode {e.returncode}', 0
    return judger(output_file, standard_file)


def compile_all(cmds):
    for x in cmds:
        # print(x)
        cpr = subprocess.run(x)
        if cpr.returncode != 0:
            return cpr.returncode
    return 0


if __name__ == '__main__':
    args = init_args()
    print('[INFO] Config:', args)
    workdir = tempfile.mkdtemp()

    main_dir = os.path.join(args.source_dir, exec_name[args.task][0])
    exec_dir = os.path.join(workdir, exec_name[args.task][1])

    compiles = {
        '4_property': [
            [
                'g++',
                '-c', os.path.join(args.source_dir, 'NumberProperty.cpp'),
                '-o', os.path.join(workdir, 'NumberProperty.o')
            ],
            [
                'g++',
                '-c', os.path.join(args.source_dir, "main.cpp"),
                '-o', os.path.join(workdir, "main.o")
            ],
            [
                'g++',
                os.path.join(workdir, "main.o"),
                os.path.join(workdir, "NumberProperty.o"),
                '-o', os.path.join(workdir, "main")
            ]
        ],
        '5_math': [
            [
                'g++',
                '-c', os.path.join(args.source_dir, "NumberProperty.cpp"),
                '-o', os.path.join(workdir, "NumberProperty.o")
            ],
            [
                'g++',
                '-c', os.path.join(args.source_dir, "Convert2Int.cpp"),
                '-o', os.path.join(workdir, "Convert2Int.o")
            ],
            [
                'g++',
                '-c', os.path.join(args.source_dir, "Sqrt.cpp"),
                '-o', os.path.join(workdir, "Sqrt.o")
            ],
            [
                'g++',
                '-c', os.path.join(args.source_dir, "main.cpp"),
                '-o', os.path.join(workdir, "main.o")
            ],
            [
                'g++',
                os.path.join(workdir, "main.o"),
                os.path.join(workdir, "NumberProperty.o"),
                os.path.join(workdir, "Convert2Int.o"),
                os.path.join(workdir, "Sqrt.o"),
                '-o', os.path.join(workdir, "main")
            ]
        ]
    }

    compile_cmd = f'g++ \"{main_dir}\" -o \"{exec_dir}\" -g -Wall --std=c++11'

    if args.task in required:
        for x in required[args.task]:
            ff_dir = os.path.join(args.source_dir, x)
            if not os.path.exists(ff_dir):
                print(f'[INFO] Missing Source Code')
                print('[SCORE] 0')
                shutil.rmtree(os.path.abspath(workdir), ignore_errors=True)
                sys.exit(0)

    if not os.path.exists(args.input_dir):
        print(f'[INFO] Missing Input File')
    elif not os.path.exists(args.standard_dir):
        print(f'[INFO] Missing Standard Output File')
    elif not os.path.exists(main_dir):
        print(f'[INFO] Missing Source Code')
        print('[SCORE] 0')
    else:
        if args.task in compiles:
            ret_code = compile_all(compiles[args.task])
        else:
            cp_pro = subprocess.run(compile_cmd, shell=True)
            ret_code = cp_pro.returncode
        if ret_code != 0:
            print('[INFO] Compile Error\n[SCORE] 0')
        else:
            for i in range(5):
                input_file = os.path.join(
                    args.input_dir, args.task + "_" + input_name[i])
                standard_file = os.path.join(
                    args.standard_dir, args.task + "_" + output_name[i])
                if not os.path.exists(input_file):
                    print(f'[INFO] Missing Input File')
                elif not os.path.exists(standard_file):
                    print(f'[INFO] Missing Standard Output File')
                else:
                    msg, score = judge(
                        input_file, standard_file,
                        exec_name[args.task][1], args.timeout,
                        workdir, args, 10, standard_judger
                    )
                    print(f'[TEST POINT {i+1}]: \n[INFO] {msg}\n[SCORE] {score}')

    shutil.rmtree(os.path.abspath(workdir), ignore_errors=True)
