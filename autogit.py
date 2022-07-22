import os

# automatically pushes to github (but you must provide commit text)

def main():
	print("****** AUTOGIT ******\n")

	be_lazy = int(input("wanna be lazy?\n0 - no\n1 - yeah\n->"))

	if be_lazy == 0:
		os.system("git add -A")
		print("git add -A")

		commit_text = input("commit text -> ")

		print(f"git commit -m '{commit_text}'")
		os.system(f"git commit -m '{commit_text}'")
		print("git push")
		os.system("git push")
	else:
		os.system("git add -A")
		print("git add -A")

		commit_text = "being lazy, no proper commit text"

		print(f"git commit -m '{commit_text}'")
		os.system(f"git commit -m '{commit_text}'")
		print("git push")
		os.system("git push")

if __name__ == '__main__':
	main()