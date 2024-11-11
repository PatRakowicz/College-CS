use std::fmt::format;
use std::fs;
use std::io::{BufRead, BufReader, Write};
use std::net::{TcpListener, TcpStream};

fn main() {
    let listener = TcpListener::bind("127.0.0.1:3000").unwrap();

    for s in listener.incoming() {
        let s = s.unwrap();
        println!("established a connection");
        handle_connection(s);
    }
}

fn handle_connection(mut stream: TcpStream) {
    let br = BufReader::new(&mut stream);
    let http_req: Vec<_> = br
        .lines()
        .map(|res| res.unwrap())
        .take_while(|l| !l.is_empty())
        .collect();

    println!("{http_req:#?}");

    let status = "HTTP/1.1 200 OK";
    let contents = fs::read_to_string("pages/home.html").unwrap();
    let l = contents.len();
    let response = format!("{status}\r\nContent-Length: {l}\r\n\r\n{contents}");

    stream.write_all(response.as_bytes()).unwrap();
}