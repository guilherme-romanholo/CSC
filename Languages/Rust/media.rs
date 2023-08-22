use std::io;

fn media(n1: f32, n2: f32) -> f32 {
    (n1 + n2) / 2.0
}

fn main() {
    let num1: f32;
    let num2: f32;
    let mut input = String::new();

    println!("Digite um número real:");
    std::io::stdin().read_line(&mut input);
    num1 = input.trim().parse().unwrap();

    input.clear();

    println!("Digite outro número real:");
    std::io::stdin().read_line(&mut input);
    num2 = input.trim().parse().unwrap();

    println!("A média entre os dois números é {}.", media(num1,num2));
}
