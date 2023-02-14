from math import exp

def f(x: float) -> float:
    return 8 * x - 2 * exp(-x)

def secant(llim: float, ulim: float, iterx: int) -> float:
    x0 = llim
    x1 = ulim
    for _ in range(0, iterx):
        x0, x1 = x1, x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))
    return x1


if __name__ == "__main__":
    u = float(input("Enter the upper limit: "))
    l = float(input("Enter the lower limit: "))
    print(f"\n{secant(l, u, 2)}\n")
