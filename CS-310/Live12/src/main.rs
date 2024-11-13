use std::fs;
use std::io::{BufRead, BufReader, Write};
use std::net::{TcpListener, TcpStream};
use Live12::ThreadPool;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:3000").unwrap();
    let pool = ThreadPool::new(10);

    for s in listener.incoming() {
        let s = s.unwrap();
        println!("established a connection");
        pool.execute(|| { handle_connection(s); });
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

    let (status, webpage) = match &http_req[..] {
        "GET / HTTP/1.1" => ("HTTP/1.1 200 OK", "pages/home.html"),
        "GET / HTTP/1.1" => ("HTTP/1.1 200 ok", "pages/info.html"),
        _ => ("HTTP/1.1 404 NOT FOUND", "page/404.html"),
    };

    let contents = fs::read_to_string(webpage).unwrap();
    let l = contents.len();
    let response = format!("{status}\r\nContent-Length: {l}\r\n\r\n{contents}");

    stream.write_all(response.as_bytes()).unwrap();
}