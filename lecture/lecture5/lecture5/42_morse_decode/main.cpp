#include <iostream>
#include <string>
#include <cctype>
#include <Map.h>
#include <Vector.h>
using namespace std;

typedef Map<char, Vector<bool>> MorseCodeMap;

MorseCodeMap createMap()
{
    MorseCodeMap m;
    m.put('A', {false, true});
    m.put('B', {true, false, false, false});
    m.put('C', {true, false, true, false});
    m.put('D', {true, false, false});
    m.put('E', {false});
    m.put('F', {false, false, true, false});
    m.put('G', {true, true, false});
    m.put('H', {false, false, false, false});
    m.put('I', {false, false});
    m.put('J', {false, true, true, true});
    m.put('K', {true, false, true});
    m.put('L', {false, true, false, false});
    m.put('M', {true, true});
    m.put('N', {true, false});
    m.put('O', {true, true, true});
    m.put('P', {false, true, true, false});
    m.put('Q', {true, true, false, true});
    m.put('R', {false, true, false});
    m.put('S', {false, false, false});
    m.put('T', {true});
    m.put('U', {false, false, true});
    m.put('V', {false, false, false, true});
    m.put('W', {false, true, true});
    m.put('X', {true, false, false, true});
    m.put('Y', {true, false, true, true});
    m.put('Z', {true, true, false, false});


    return m;
}

string encodeLetter(const MorseCodeMap& m, char ch)
{
    if (!m.containsKey(ch))
        return "";

    const Vector<bool>& v = m[ch];
    string result;
    for (int i = 0; i < v.size(); i++) {
        if (v[i])
            result += '-';
        else
            result += '.';
    }
    return result;
}

string encodeString(const MorseCodeMap& m, const string& str)
{
    string result;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!isalpha(ch)) continue;

        string s = encodeLetter(m, toupper(ch));
        if (s.empty())
            return "";
        result += s + " ";
    }
    return result;
}

/* Decoding */
Map<string, char> decodeMap()
{
    MorseCodeMap m = createMap();
    Map<string, char> dm;
    for (char l : m) {
        string s = encodeLetter(m, l);
        dm.put(s, l);
    }
    return dm;
}

Vector<string> extractWords(const string& str)
{
    Vector<string> words;

    int st = 0, ed = 0;
    while (true) {
        while (st < str.length() && str[st] == ' ')
            st++;
        if (st == str.length()) break;

        ed = st;
        while (ed < str.length() && str[ed] != ' ')
            ed++;
        words.add(str.substr(st, ed-st));

        st = ed;
    }

    return words;
}

string decodeString(const string& str)
{
    Map<string, char> dm = decodeMap();
    Vector<string> words = extractWords(str);

    string res;
    for (int i = 0; i < words.size(); i++) {
        string w = words[i];
        if (!dm.containsKey(w))
            return "";

        char ch = dm[w];
        res += ch;
    }
    return res;
}

int main()
{
    MorseCodeMap m = createMap();
    string estr = encodeString(m, "CHINA");
    cout << estr << endl;
    cout << decodeString(estr) << endl;
    return 0;
}
