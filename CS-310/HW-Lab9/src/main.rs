use std::cell::RefCell;
use std::rc::Rc;

struct Node {
    val : i32,
    next: Option<Rc<RefCell<Node>>>
}

impl Node {
    fn new(val: i32) -> Self {
        Node { val, next: None }
    }

    fn append(&mut self, val: i32) {
        match self.next {
            None => { self.next = Some(Rc::new(RefCell::new(Node::new(val)))) }
            Some(ref mut next_node) => { next_node.append(val) }
        }
    }

    fn length(&self) -> usize {
        match &self.next {
            Some(next_node) => 1 + next_node.length(),
            None => 1,
        }
    }
}

#[test]
fn test_append() {
    let mut list = Node::new(1);
    list.append(2);
    list.append(3);
    assert_eq!(list.length(), 3)
}

fn main() {
}


