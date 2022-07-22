import os

def main():
	os.system("git add -A")

	commit_text = input("commit text ->")

	os.system(f"git commit -m '{commit_text}'")
	os.system("git push")

if __name__ == '__main__':
	main()