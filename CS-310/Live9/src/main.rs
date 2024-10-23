use core::ops::Drop;
use std::rc::Rc;
use crate::List::{Cons, Nil, Theend};

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

    let r = Rc::new(Cons(1, Rc::new(Theend)));
    let s = Cons(2, Rc::clone(&r));
    let t = Cons(3, Rc::clone(&r));

}

//recursive struct
enum List {
    Cons(i32, Rc<List>),
    Theend
}

pub trait Messenger { fn send(&mut self, msg: &str); }
pub struct LimitTracker<'a, T: Messenger> {
    messanger: &'a T,
    value: usize,
    max: usize
}

impl <'a, T> LimitTracker<'a,T> where T:Messenger {
    pub fn new(messager: &'a T, max:usize,) -> LimitTracker<'a, T> {
        LimitTracker {
            messanger,
            value: 0,
            max
        }
    }
    pub fn update_value(&mut self, value:usize) {
        self.value = value;
        let persent = self.value as f64 / self.max as f64;
        if persent > 1.0 {
            self.messanger.send("You are over your data limit");
        } else {
            self.messanger.send("You are over 80% of your limit");
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    struct MockMsg { sent_messages : Vec<String> }
    impl MockMsg { fn new() -> Self { MockMsg { sent_messages: Vec::new() } } }
    impl Messenger for MockMsg {
        fn send(&mut self, msg: &str) {
            self.sent_messages.push(String::from(msg))
        }
    }

    #[test]
    fn sens_warning_msg() {
        let mock = MockMsg::new();
        let mut limit = LimitTracker::new(&mock, 100);
        limit.update_value(85);
        assert_eq!(mock.sent_messages.len(), 1)
    }
}

struct CustSmart {
    data : String
}


impl Drop for CustSmart {
    fn drop(&mut self) {
        println!("Dropping our struct {}", self.data)
    }
}
