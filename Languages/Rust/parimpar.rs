use std::io;

fn main() {
    let mut input = String::new();
    let num: i32;

    println!("Digite um número:");
    std::io::stdin().read_line(&mut input);

    num = input.trim().parse().unwrap();

    if num % 2 == 0 {
        println!("O número é par!");
    } else {
        println!("O número é ímpar!");
    }   
}

