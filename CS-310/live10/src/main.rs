use std::sync::mpsc;
use std::thread;
use std::time::Duration;

fn main() {
/*
    let v = vec![0,0,0];
    let handle = thread::spawn(move || {
       for i in 1..10 {
           println!("Number {i} in thread");
           println!("{v:?}");
           thread::sleep(Duration::from_millis(2));
       }
    });

    handle.join().unwrap();

    for i in 1..5 {
        println!("number {i} in main function");
        thread::sleep(Duration::from_millis(2));
    }
    // handle.join().unwrap();
*/
    // ++++++++++++++++++++++++++++++++++++++++
    // Multiple producer, single consumer
    let (tx, rx) = mpsc::channel();
    thread::spawn(move || { tx.send(String::from("Whatsup")).unwrap(); });

    // rcev() and try_rcev() -> will check for messages constantly
    let rcv = rx.recv().unwrap();
    println!("{rcv}");

    // ++++++++++++++++++ input of a vector +++++++++++++++++
    let (tx, rx) = mpsc::channel();

    let tx1= tx.clone();

    thread::spawn(move || {
        let vals = vec![String::from("more"),String::from("messages")];
        for val in vals {
            tx1.send(val).unwrap();
            thread::sleep(Duration::from_secs(2));
        }
    });

    thread::spawn(move || {
        let vals = vec![String::from("its"),String::from("a"),String::from("message")];
        for val in vals {
            tx.send(val).unwrap();
            thread::sleep(Duration::from_secs(2));
        }
    });
    
    // rcev() and try_rcev() -> will check for messages constantly
    for rcv in rx {
        println!("arived {rcv}");
    }



}
