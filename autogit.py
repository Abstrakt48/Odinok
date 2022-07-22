import os

def main():
	print("****** AUTOGIT ******")

	os.system("git add -A")
	print("git add -A")

	commit_text = input("commit text -> ")

	os.system(f"git commit -m '{commit_text}'")
	print(f"git commit -m '{commit_text}'")
	os.system("git push")
	print("git push")

if __name__ == '__main__':
	main()