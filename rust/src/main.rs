use std::io;

pub fn get_roman(mut number: i32) -> String {
    let mut res = String::new();
    let roman_num: [&str; 25] = [
        "_M", "_C_M", "_D", "_C_D", "_C", "_X_C", "_L", "_X_L", "_X", "_I_X", "_V", "_I_V", "M",
        "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
    ];
    let values: [i32; 25] = [
        1000000, 900000, 500000, 400000, 100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000,
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
    ];
    for i in 1..25 {
        while number - values[i] >= 0 {
            res += roman_num[i];
            number -= values[i];
        }
    }
    return res;
}

fn main() {
    println!("Enter a number: ");
    let mut number = String::new();
    io::stdin()
        .read_line(&mut number)
        .expect("Failed to read input");
    let my_int = number.trim().parse::<i32>().unwrap();
    println!("You entered: {}", my_int);
    number = get_roman(my_int);
    println!("In roman numerals: {}", number)
}
