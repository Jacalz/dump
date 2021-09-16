from math import ceil

# round_nearest10 rounds to the nearest factor of 10.
def round_nearest10(num):
	return ceil(num / 10) * 10

# num_sum returns the sum of the individual numbers within the number.
# It expects numbers to be below 100 (we will never go above 9*2=18 any way).
def num_sum(num):
	return (num - num % 10) // 10 + num % 10

# get_product returns the sum of all number sums except the last number.
# Every other number is multiplied by two.
def get_product(pnum):
    sum = 0
    for i, num in enumerate(pnum[:-1]):
        sum += num_sum(num * (2 - i % 2))

    return sum

def check_pnr(pnum):
	sum = get_product(pnum)
	ctrl = round_nearest10(sum) - sum

	return ctrl == pnum[-1]

if __name__ == "__main__":
	print(check_pnr([7, 2, 0, 1, 2, 3, 1, 2, 3, 5]))
	print(check_pnr([7, 4, 0, 2, 1, 7, 4, 8, 2, 0]))
	print(check_pnr([7, 4, 0, 2, 1, 7, 4, 8, 2, 1]))
