use std::sync::{mpsc, Arc, Mutex};
use std::thread;

pub struct ThreadPool {
    threads: Vec<Worker>
}

struct Worker {
    thread: thread::JoinHandle<()>,
}
impl ThreadPool {
    pub fn new(nthreads: usize) -> ThreadPool {
        if (nthreads > 0) {
            let(tx, rx) = mpsc::channel();
            let rx = Arc::new(Mutex::new(rx));

            let mut threads = Vec::with_capacity(nthreads);
            for i in 0..nthreads { threads.push(Worker::new(Arc::clone(&rx))) }
            ThreadPool { threads }
        } else {
            panic!("")
        }
    }
    pub fn execute<F>(&self, f: F) where F: FnOnce() + Send + 'static, {

    }
}

impl Worker {
    fn new(rx: Arc<Mutex<mpsc::Receiver<()>>>) -> Worker {
        let thread = thread::spawn(|| { rx; });
        Worker { thread }
    }
}
