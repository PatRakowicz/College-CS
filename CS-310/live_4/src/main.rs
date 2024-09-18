#[derive(Debug)]
enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

impl IpAddr {
    fn call(&self) {
        self;
    }
}

struct User {
    ip_addr: IpAddr,
    email: String,
    username: String,
    sign_in_count: u64,
    active: bool,
}

enum Account {
    user_Account(User)
}

/*struct pushMessage {
    msg: String,
}

struct pullMessage {
    msg: String,
}

fn sends_push(msg: pushMessage) {}
fn sends_pull(msg: pullMessage) {}
*/
enum message {
    pullMessage,
    pushMessage,
}

enum Generation {
    GenAlpha,
    GenZ,
    Millennial,
    GenX,
    Boomer,
    SilentGeneration,
}
fn generation_to_years(gen: Generation) -> (i32, i32) {
    match gen {
        Generation::GenAlpha => (2013, 2024),
        Generation::GenZ => (1985, 2012),
        Generation::Millennial => (1965, 1984),
        Generation::GenX => (1945, 1964),
        Generation::Boomer => (1945, 1964),
        Generation::SilentGeneration => (0, 1944)
    }
}

fn sends(msg: message) {}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1)
    }
}

fn main() {
    let ip4 = IpAddr::V4(127, 8, 10, 1);
    let ipv6 = IpAddr::V6("e4::5g::...".to_string());

    println!("{:#?}", ip4);

    let g = Generation::Boomer;
    let (year1, year2) = generation_to_years(g);
    println!("{}-{}", year1, year2);

    let s = Some(5);
    let y = 3;
    let n: Option<i32> = None;

    let sum = match s {
        Some(j) => j + y,
        None => 0
    };
}
