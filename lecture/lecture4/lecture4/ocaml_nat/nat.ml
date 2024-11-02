(* ADT for natural numbers *)
module type NAT =
  sig
    type nat
    val from_int:   int -> nat
    val add:        nat -> nat -> nat
    val print_nat:  nat -> unit
  end

(* ADT Definition *)
module Nat : NAT =
  struct
    type nat = int list

    (* generate from integers *)
    let rec from_int i = 
      if i > 0 then
        (i mod 10) :: (from_int (i/10))
      else
        []

    (* addition of digits *)
    let add_digits a b c = 
      let v = a + b + c in
      (v mod 10, v / 10)

    (* addition *)
    let rec add_with_carry a b c =
      match a, b with
      | [], [] -> 
        if c = 0 then [] else [c]
      | av::a', [] -> 
        let (v, c') = add_digits av 0 c in
        v :: (add_with_carry a' [] c')
      | [], bv::b' -> 
        let (v, c') = add_digits 0 bv c in
        v :: (add_with_carry [] b' c')
      | av::a', bv::b' ->
        let (v, c') = add_digits av bv c in
        v :: (add_with_carry a' b' c')
        
    let add a b =
      add_with_carry a b 0
 

    (* print *)
    let rec print_nat_aux n =
      match n with
      | [] -> ()
      | h :: n' -> 
        print_nat_aux n';
        Printf.printf "%d" h

    let print_nat n = 
      print_nat_aux n;
      Printf.printf "\n"

  end
