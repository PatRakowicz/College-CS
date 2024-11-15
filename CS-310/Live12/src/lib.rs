use std::sync::{mpsc, Arc, Mutex};
use std::thread;

pub struct ThreadPool {
    threads: Vec<Worker>,
    tx: mpsc::Sender<Job>
}

struct Worker {
    thread: thread::JoinHandle<()>,
}
type Job = Box<dyn FnOnce() + Send + 'static>;

impl ThreadPool {
    pub fn new(nthreads: usize) -> ThreadPool {
        if (nthreads > 0) {
            let(tx, rx) = mpsc::channel();
            let rx = Arc::new(Mutex::new(rx));

            let mut threads = Vec::with_capacity(nthreads);
            for i in 0..nthreads { threads.push(Worker::new(Arc::clone(&rx))) }
            ThreadPool { threads, tx }
        } else {
            panic!("")
        }
    }
    pub fn execute<F>(&self, f: F) where F: FnOnce() + Send + 'static, {
        self.tx.send(Box::new(f)).unwrap()
    }
}

impl Worker {
    fn new(rx: Arc<Mutex<mpsc::Receiver<Job>>>) -> Worker {
        let thread = thread::spawn(|| { rx; });
        Worker { thread }
    }
}
