pub struct Patrons {
    pub name: String,
}

pub static mut PATRONS: Vec<Patrons> = Vec::new();

pub fn add_patron(name: &str) {
    let p = Patrons { name: name.to_string() };

    unsafe { PATRONS.push(p); }
}

pub fn list_patrons() {
    let mut s = String::new();
    for p in unsafe {&PATRONS} {
        s.push_str(&p.name);
        s.push_str("\n");
    }
}