use std::error::Error;
use std::fs;

pub struct Config {
    pub file_path: String
}

impl Config {
    /*pub fn parse_args(args: &[String]) -> Result<Config, &'static str> {
        if args.len() < 2 { return Err("Not valid arguments"); }
        let file_path = args[1].clone();
        Ok(Config { file_path })
    }*/

    pub fn parse_args(mut args: impl Iterator<Item = String>) -> Result<Config, &'static str> {
        args.next();
        let file_path = match args.next() {
            Some(arg) => arg,
            None => return Err("Missing argument file path")
        };
        Ok(Config {file_path})
    }
}


pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.file_path)?;
    println!("{contents}");
    Ok(())
}