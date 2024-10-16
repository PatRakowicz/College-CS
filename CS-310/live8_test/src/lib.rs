pub fn add(left: u64, right: u64) -> u64 {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let x = 2;
        let y = 2;
        let result = add(x, y);
        assert_eq!(result, 4);
    }

    #[test]
    #[should_panic(expected = "FAIL")]
    fn more_tests() {
        panic!("FAIL")
    }

    #[test]
    fn contains() {
        let result = "hello";

        // assert!(result.contains("meow"));
        // assert_eq!(result.contains("meow"), false);
        assert_ne!(result, "meow");
    }

    #[test]
    fn mytestworks() -> Result<(), String>{
        let result = add(2, 2);
        if result == 4 { Ok(()) }
        else { Err(String::from("2 plus 2 is not four")) }
    }
}
