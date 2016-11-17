#! /env/python

def main():
    s = set()
    for a in range(2, 101):
        for b in range(2, 101):
            s.add( a**b )
    print(len(s))

if __name__ == "__main__":
    main()

# AC ans = 9183
