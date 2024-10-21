use core::ops::Drop;
use std::rc::Rc;
use crate::List::{Cons, Nil};

fn main() {
    // Drop example
    let cp1 = CustSmart {
      data: String::from("i will be dropped")
    };
    println!("cp1 created");
    drop(cp1);

    let cp2 = CustSmart {
        data: String::from("Like its hot")
    };
    println!("cp1 created");

    // Smart Pointer
    let x = 5;
    let y = Box::new(x);
    println!("{}", *y);

    // recursive type
    // let ls = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Nil))))));

    let r = Rc::new(Cons(1, Rc::new(Nil)));
    let s = Cons(4, Rc::clone(&r));
}

//recursive struct
enum List {
    Cons(i32, Rc<List>),
    Nil
}

struct CustSmart {
    data : String
}


impl Drop for CustSmart {
    fn drop(&mut self) {
        println!("Dropping our struct {}", self.data)
    }
}
