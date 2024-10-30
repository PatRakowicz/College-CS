//imports (includes those needed for the homework)
use std::fs::File;
use std::io::Write;
use std::sync::mpsc::Receiver;
use std::sync::{mpsc, Arc, Mutex};
use std::{fs, thread, vec};
use std::time::Duration;
use rand::Rng; // Add `rand` crate to cargo.toml: rand = "0.8.4"

// Create struct LogReceiver
// TODO: add variable receiver of type mpsc::Receiver<> which will receive String messages
struct LogReceiver {
    receiver: mpsc::Receiver<String>,
}

//implemented constructor and function "logging"
impl LogReceiver {
    fn new(rx: Receiver<String>) -> Self {
        Self { receiver: rx}
    }
    // Logging function: prints out the log message received
    // We are checking if the receiver return on Ok(String) value by assigning the value to a variable
    // Only as long as we get back an Ok, will the logger print the message.
    fn logging(&mut self) {
        while let Ok(log) = self.receiver.recv() {
            println!("Log: {}", log);
        }
    }
}

fn main() {
    //Initialize a channel and get the transmitter and receiver objects
    let (log_tx, log_rx) = mpsc::channel();

    // TODO: Initialize a LogReceiver using the just initialized receiver object
    let mut logRecever = LogReceiver { receiver };

    // TODO: Spawn a SINGLE thread to handle logging, 
    // inside the thread call the logging method we defined for our LogReceiver struct 
    thread::spawn(move || { logRecever.logging() });

    // TODO: Use a for loop to spawn multiple threads to handle "requests" (minimum of 5 threads)
    {
        // TODO: Clone the transmitter

        // TODO: spawn threads
        {
            // random number generator to vary the duration of thread spawning
            let duration = rand::thread_rng().gen_range(1..4);

            // TODO: use generated duration to make thread sleep

            // Generate log message
            let log_message = format!("Request {} processed in {} seconds", i, duration);

            //TODO: Send log message over transmitter
        }
    }

    //TODO: release transmitter by dropping it

    //TODO: Call join() on appropriate handle to make sure threads do not end prematurely


}