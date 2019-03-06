let explode s =
  let rec exp i l = if i < 0 then l else exp (i - 1) (s.[i] :: l) in
  exp (String.length s - 1) []

let check_palindrome s1 =
  let helper v =
    match v with
    Some x -> x + 1;
    | None -> 1
  in 
  let tbl =
    List.fold_left
      (fun acc x -> Hashtbl.replace acc x (helper (Hashtbl.find_opt acc x)) ; acc)
      (Hashtbl.create (List.length (explode s1)))
      (explode s1)
  in
  let counts = Hashtbl.fold (fun _ v acc -> v :: acc) tbl []
  in 
  (List.fold_left (fun acc x -> acc + x) 0 (List.map (fun x -> x mod 2) counts)) < 2

  (* ;;
  Printf.printf "%b\n" (check_palindrome "abc")  *)
