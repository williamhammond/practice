let explode s =
  let rec exp i l = if i < 0 then l else exp (i - 1) (s.[i] :: l) in
  exp (String.length s - 1) []

let check_permutation s1 s2 =
  List.sort compare (explode s1) = List.sort compare (explode s2)

let check_permutation_n s1 s2 =
  let s1_tbl =
    List.fold_left
      (fun acc x -> Hashtbl.add acc x true ; acc)
      (Hashtbl.create (List.length (explode s1)))
      (explode s1)
  in
  let s2_tbl =
    List.fold_left
      (fun acc x -> Hashtbl.add acc x true ; acc)
      (Hashtbl.create (List.length (explode s2)))
      (explode s2)
  in
  compare s1_tbl s2_tbl = 0

;;
Printf.printf "%b\n" (check_permutation "a" "a")

;;
Printf.printf "%b\n" (check_permutation_n "a" "ab")
