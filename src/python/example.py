from include.gms import gms

while True:
	szSelect = input("Make select (file, text): ")

	if szSelect == "file":
		szFileName = input("Enter file path: ")

		try:
            with open(szFileName, "rb") as file:
                byte = file.read()
                print(gms(str(byte)[2:-1]))
                
        except Exception as e:
            print(str(e))

	elif szSelect == "text":
		print(gms(input("Enter text to hash: ")))