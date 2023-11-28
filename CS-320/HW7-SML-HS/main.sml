(* Problem 1 *)
fun remFirst (x, []) = []
  | remFirst (x, y::ys) = if x = y then ys else y::remFirst(x, ys);

(* Problem 2 *)
fun mergeElement (x, []) =[]
  | mergeElement (x, y::ys) = if x < = y then x::y::ys else y::mergeElement(x, ys);

(* Problem 3 *)
fun mySort [] = []
  | mySort (x::xs) = mergeElement(x, mySort xs);

(* Problem 4 *)
fun difList (l, k) = List.foldl (fn (x, acc) => if x mod k = 0 then acc else x::acc) []

(* Problem 5 *)
fun mergeList ([], l2) = l2
  | mergeList (l1, []) = l1
  | mergeList (x::xs, y:ys) = if x <= then x::mergeList(xs, y::ys) else y::mergeList(x::xs, ys);
