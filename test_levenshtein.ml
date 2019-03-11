open Core;;

let memoize f =
  let memo_table = Hashtbl.Poly.create () in
  (fun x ->
     Hashtbl.find_or_add memo_table x ~default:(fun () -> f x))

let memo_rec f_norec x =
  let fref = ref (fun _ -> assert false) in
  let f = memoize (fun x -> f_norec !fref x) in
  fref := f;
  f x

let memo_edit_distance = memo_rec (fun edit_distance (s,t) ->
  match String.length s, String.length t with
  | (0,x) | (x,0) -> x
  | (len_s,len_t) ->
    let s' = String.drop_suffix s 1 in
    let t' = String.drop_suffix t 1 in
    let cost_to_drop_both =
      if Char.(=) s.[len_s - 1] t.[len_t - 1] then 0 else 1
    in
    List.reduce_exn ~f:Int.min
      [ edit_distance (s',t ) + 1
      ; edit_distance (s ,t') + 1
      ; edit_distance (s',t') + cost_to_drop_both
])

let rec edit_distance s t =
  match String.length s, String.length t with
  | (0,x) | (x,0) -> x
  | (len_s,len_t) ->
    let s' = String.drop_suffix s 1 in
    let t' = String.drop_suffix t 1 in
    let cost_to_drop_both =
      if Char.(=) s.[len_s - 1] t.[len_t - 1] then 0 else 1
    in
    List.reduce_exn ~f:Int.min
      [ edit_distance s' t  + 1
      ; edit_distance s  t' + 1
      ; edit_distance s' t' + cost_to_drop_both
      ]

let time f =
  let open Core in
  let start = Time.now () in
  let x = f () in
  let stop = Time.now () in
  printf "Time: %F ms\n" (Time.diff stop start |> Time.Span.to_ms);
  x
;;