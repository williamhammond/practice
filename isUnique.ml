#!/usr/bin/env utop


let rec is_unique l = match l with
  []       -> true
  | (h::t) ->
  let x = (List.mem h t) in
  if (not x) then is_unique t else false;;



print_string (string_of_bool((is_unique[1;2;3;4;4])));;