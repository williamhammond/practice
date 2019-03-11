let print_matrix a = 
  let n = Array.length a in
  for i=0 to n - 1 do
    for j=0 to n - 1 do
      Printf.printf "%d " a.(i).(j);
    done;
    Printf.printf "\n";
  done

let rotate_matrix a = 
  let n = Array.length a in
  for i=0 to n / 2 do
    for j=0 to n - i - 1 do
      let tmp = a.(i).(j) in
      a.(i).(j) <- a.(n - 1 - j).(i);
      a.(n - 1 - j).(i) <- a.(n - 1 - i).(n - 1 - j);
      a.(n - 1 - i).(n - 1 - j) <- a.(j).(n - 1 - i);
      a.(j).(n - 1 - i) <- tmp;
    done;
    print_matrix a;
    Printf.printf "\n";
  done;
  a
;;