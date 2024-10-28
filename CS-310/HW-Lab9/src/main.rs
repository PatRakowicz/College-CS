use std::cell::RefCell;
use std::rc::Rc;

/*
1) The Box<> is a smart pointer that allows for the data that is given to be on the heap
and not on the stack. If we were to put them on the stack we would have to deal with each node
together and not allow for each node to be dealt with independently, that why we put them on the
heap. This allows us to store the nodes independently and keep the idea of recursive types
being stored differently to allow for pointing to other nodes separately.

2) The Option<> allows for the data to have the possibility to represent something to have nothing next
or in other words Option allows for the option of having an empty state, which is needed for something
like a linked list. This allows for an item to have something empty and not throw any errors, and have
the last item of the list to have a none parameter.

3) borrow_mut and borrow are different but do the same thing. Borrow_mut allows to borrow the given element
and update according to the code. and borrow allows us to reference the object without the need to update
at a later state. Or in other words borrow_mut allows to borrow the object and update accordingly, and
borrow is just a passable immutable reference to the object (read-only).

4.1) Clone allows us to create a new pointer that shares the same data, but does not allow for the duplicaion of data.
In other words, it increases the shared count but does not duplicate the data provided inside each node

GAI => (Rust, RC strong count what is it)
4.2) Given we are using RC or Referenced Counted, this is a smart pointer that allows for us to use
shared ownership of the data provided. The strong count is the idea of how many active references to the data its given.
Given that it's getting information of how many instances are pointing to the same data, if this number stays above
0 the data will remain in the memory. There is also weak count, this is just the opposite of strong where
the reference is non-owning, allowing for the lifespan of the data to not be affected.

4.3) the idea of drop(node) and node.drop() are different because drop.{} directly is the idea of a trait method
while drop() is just a deconstruct of the passed in value, or node, allowing for the data inside to be seen
then later dropped and cleaned from memory. Given how rust is implemented the .drop cant be used because even if
it's used in the same manner, there could be problems on how that data is being dropped given compile start.
Thus rust disables this feature entirely and forces to use drop() directly to allow for the compiler to not be stuck

5.1) node.next allows for the compiler to see if the data inside the given Option<> is another node or null, allowing for
it to know if there is a next node or if it's empty.
5.2) .as_ref() allows for the given use to be a reference and not ownership of the item. This is needed because we only
want a reference to the next node and not grab ownership so we don't use or remove in any way of the next node.
5.3) .unwrap() is just grabbing data and removing it from the Some option, assuming that next.node is not null
otherwise it will throw errors (or panic). This allows us to use the Rc<RefCell<Node>>> as a referenced-counted pointer
to the RefCell containing the next node.
5.4) .borrow() just allows us to the data inside the parameters to be seen as an immutable reference, allowing for read of
the content inside the Node while keeping the borrow rules, even if the Node is in a shared ownership state.
5.5) .val is just allowing us to grab the data (value) inside the node, and returned as an actual integer or some
value that is predefined.

allowing for the code to check if node.next holds a value of 2 inside the node data, if not it will fail.
*/

struct Node {
    val : i32,
    next: Option<Rc<RefCell<Node>>>
}

impl Node {
    fn new(val: i32) -> Self {
        Node { val, next: None }
    }

    fn set_value(&mut self, new_val: i32) {
        self.val = new_val;
    }

    fn append(&mut self, val: i32) {
        match self.next {
            None => { self.next = Some(Rc::new(RefCell::new(Node::new(val)))) }
            Some(ref mut next_node) => { next_node.borrow_mut().append(val) }
        }
    }

    fn length(&self) -> usize {
        match &self.next {
            Some(next_node) => 1 + next_node.borrow().length(),
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

#[test]
fn test_rc_shared_ownership() {
    let node1 = Rc::new(RefCell::new(Node::new(1)));
    let node2 = Rc::clone(&node1);
    assert_eq!(Rc::strong_count(&node1), 2);
    drop(node2);
    assert_eq!(Rc::strong_count(&node1), 1);
}
#[test]
fn test_refcell_mutability() {
    let node = Rc::new(RefCell::new(Node::new(1)));
    node.borrow_mut().set_value(10);
    assert_eq!(node.borrow().val, 10);
}
#[test]
fn test_append_refcell() {
    let mut node = Node::new(1);
    node.append(2);
    node.append(3);
    assert_eq!(node.next.as_ref().unwrap().borrow().val, 2);
}

fn main() {
}


