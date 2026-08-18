All datatypes are prefixed using their identifier symbol. The identifier symbol only needs to be used at the declaration of the variable

# Integer

Integer `#` which is used to hold a whole number. 

Example: 

`#value = 20`

Booleans can leak into integers. `0` and `1` can represent true and false using boolean extension. Do not worry, even declaring `#num1 = 1` when going to add `num1` to another number it will still calculate as the value 1. If any characters are attached to the values `1` or `0` or in a unique scope it'll immediately shift to a number instead of a boolean value

```
; would visually be a boolean but act as either
#func add(num) {
    send num + 1
}

; will only act as a integer
#func sub(num) {
    send num - 12 
    ; since 1 is connected to 2 its not longer a boolean and visually will change in VSCode
}
```

### C translation: 

`int value = 20;`

### Rust translations:

Inf: `let value = 20;`

Exp: `let value: i32 = 20;`

Mut: `let mut value = 20;`

# Decimal

Decimal/Floating point `%` is used to hold a decimal or floating point number. Without declaration, default amount of placements are 1.

`%value = 2.5`

You can declare the amount of places past the `.` by using squared brackets. This also applies to input.

`%value[5] = 2.12345`

### C translation:

```
// converted to a string
char value; sprintf(value, "%.5f", 2.12345);
```

### Rust translation:
```
// converted to a string
let value: f64 = 2.12345;
let formatted = format!("{:.5}", value); 
```

# String

Strings `@` are used to hold an array of characters which represent sentances or words. Strings internally are recognized as a list of characters in a dynamic array.

`@str = "hi"`

```
@str = "hello"
; compiler would characterize as: 'h', 'e', 'l', 'l', 'o'
```

You can still represent single characters with a small change in the code. Using `' '` instead of `" "` the compiler will expect a single character instead of more than one character.

`@str = 'A'` 

### C translation:

### Rust translation:

# Nil

# CCP

While CCP's arent directly datatypes, they do have a dedicated identifier `?` to access the wide range of compiler commands.

See CCP.md for more in depth documentation on Compiler Control Processes.