def mem_decorator(func):
    cache = {}
    def wrapper(*args, **kwargs):
        key = args + tuple(sorted(kwargs.items()))
        if key not in cache:
            cache[key] = func(*args, **kwargs)
        return cache[key]
    return wrapper

def count_decorator(func):
    def wrapper(*args, **kwargs):
        wrapper.count += 1
        return func(*args, **kwargs)
    wrapper.count = 0
    return wrapper 

@count_decorator
@mem_decorator
def fib(n):
    if n in (0, 1):
        return 1 
    return fib(n-1) + fib(n-2)


def main():
    print(fib(37))
    print(fib.count)


if __name__ == "__main__":
    main()

