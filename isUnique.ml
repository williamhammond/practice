let rec is_unique l =
  match l with
  | [] -> true
  | h :: t ->
      let x = List.mem h t in
      if not x then is_unique t else false

let explode s =
  let rec exp i l = if i < 0 then l else exp (i - 1) (s.[i] :: l) in
  exp (String.length s - 1) []

let is_str_unique s = is_unique (explode s)

;;
print_string (string_of_bool (is_unique [1; 2; 3; 4; 4]))

;;
print_string (string_of_bool (is_str_unique "aabc"))
