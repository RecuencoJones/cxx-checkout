## Statements

- Can create instance of checkout
- Can add an item
- Can add an item price
- Can calculate the current total
- Can add multiple items and get correct total
- Can add discount rules
- Can apply discount rules to the total
- Exception is thrown for item added without price for the item

## Setup

```
mkdir -p build && cd build
conan install ..
cmake ..
```

## Build && Run

```
make main
./bin/main
```

## Test

```
make test
./bin/test
```

## TDD

```
find ../src ../test | entr sh -c 'cmake ..; make test; ./bin/test'
```