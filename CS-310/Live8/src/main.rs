use std::{env, io};
use std::fs::File;
use std::io::Read;
use log::error;

fn main() {
    // env::set_var("RUST_BACKTRACE=1", "1");
    // panic!("text panic")

    let v = vec![0, 5, 10];
    // v[100];

    //OPTION enum
    // Some() and None

    //RESULT enum
    //  Ok(result) and Err(error
    //
    let file_result_enum = File::open("afile.txt");
    /*let file = match file_result_enum {
        Ok(file) => file,
        Err(error) => panic!("File did not want to open today")
    };*/

    // let file = File::open("afile.txt").unwrap();
    /*let file = File::open("hello.txt").expect("file cannot be found");

    let file = match file_result_enum {
        Ok(file) => file,
        Err(error) => match error.kind() {
            io::ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(created) => created,
                Err(error2) => {
                    panic!("Cannot create the file")
                },
            },
            _ => {panic!("Could not open file")},
        }
    };

    let file = File::open("hello.txt").unwrap_or_else(|error| {
        if error.kind() == io::ErrorKind::NotFound {
            File::create("hello.txt").unwrap_or_else(|error| panic!("No Open"))
        } else {
        panic!("other problems");
        }
    });
}*/
}
fn read_content_from_file() -> Result<String, io::Error> {
    let fresult = File::open("afile.txt");
    let mut file = match fresult {
        Ok(file) => file,
        Err(error) => return Err(error)
    };
    let mut contents = String::new();
    match file.read_to_string(&mut contents) {
        Ok(_) => Ok(contents),
        Err(e) => Err(e)
    }
}

