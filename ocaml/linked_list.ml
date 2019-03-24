exception Empty_list

type 'a my_list = Nil | List of 'a * 'a my_list

let head = function 
     Nil -> raise Empty_list
   | List(e,_) -> e;;

let tail = function
    Nil -> Nil
   | List(_,t) -> t