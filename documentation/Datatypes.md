All datatypes are prefixed using their identifier symbol. The identifier symbol only needs to be used at the declaration of the variable

# Integer

Integer `#` which is used to hold a whole number. 

Example: 

`#value = 20`

Booleans can leak into integers. `0` and `1` can represent true and false using boolean extension. Do not worry, even declaring `#num1 = 1` when going to add `num1` to another number it will still calculate as the value 1. If any characters are attached to the values `1` or `0` or in a unique scope it'll immediately shift to a number instead of a boolean value

```n
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

```c
int value = 20;
```

### Rust translations:

```rs
// Inf:
let value = 20

// Exp: 
let value: i32 = 20;

// Mut: 
let mut value = 20;
```

# Decimal

Decimal/Floating point `%` is used to hold a decimal or floating point number. Without declaration, default amount of placements are 1.

```n
%value = 2.5
```

You can declare the amount of places past the `.` by using squared brackets. This also applies to input.

`%value[5] = 2.12345`

### C translation:

```c
// converted to a string
char value; sprintf(value, "%.5f", 2.12345);
```

### Rust translation:
```rs
// converted to a string
let value: f64 = 2.12345;
let formatted = format!("{:.5}", value); 
```

# String

Strings `@` are used to hold an array of characters which represent sentances or words. Strings internally are recognized as a list of characters in a dynamic array.

`@str = "hi"`

```n
@str = "hello"
; compiler would characterize as: 'h', 'e', 'l', 'l', 'o'
```

You can still represent single characters with a small change in the code. Using `' '` instead of `" "` the compiler will expect a single character instead of more than one character.

`@str = 'A'` 

### C translation:

`char str[3] = "hi";`

### Rust translations:

String Slice: `let s: &str = "hi";`

Stack Alloc: `let s = InlineString::<3>::from_str("hi").unwrap();`

# Nil

Nil is a way to represent an empty memory location for a variable. To declare a nil variable the identifier `$`. Alternatively you can also represent a nil variable but still have a declaration type `# @ %` by importing boolean values `using boolean`

Normal: cant take in data until type is changed.

`$hello`

The most common case of a nil datatype identifier versus using the nil keyword is when declaring `func main()`, void pointers, or a func which you dont want to return a datatype

When typing main, itll autofill to a nil function as it wont return anything as its the main execution point of the program, this can be change in less common situations but mostly main will remain a nil function.

```
$func main() {
    
    kill
}
```

For nil pointers, nil `$` is often used to store a memory address but not a value. Nil pointers can be tricky and are typically used in more complex scenarios as referencing and dereferencing a nil pointer can be hard to understand

```
using terminal

#num = 20 ; holds the value 20
$ptr = ->num ; holds no value but has the address of num

;-
when trying to dereference a nil pointer you can either use a new variable 
or use the original variable and convert it back to a value later
-;

; new var
#newPtr = <-num 
terminal.out(newPtr) ; would produce 20

; using .typeBypass()
ptr = <-num ; would store the 20 from the original num value but wouldnt have any info on it
terminal.out(ptr) ; would return no value

terminal.typeBypass(# ; becauase num = 20).out(ptr) ; would produce 20
```

When using nil `$` for regular functions, like in most languages

```
using terminal

$func hello() {
    terminal.out("hello")
}
```

Using boolean: can take in data of declared type once nil is changed

```
using boolean

#num1 = nil
num = 10
```

### C translations:

Sentinel value: 

```
#define INT_NIL - 1

int num = INT_NIL;
```

Pointer: `int *num = NULL;`


### Rust translations:

Normal: `let mut num: Option<i32> = None;`

Pointer: `let mut num: Option<&i32> = None;`

# CCP

While CCP's arent directly datatypes, they do have a dedicated identifier `?` to access the wide range of compiler commands.

See CCP.md for more in depth documentation on Compiler Control Processes.