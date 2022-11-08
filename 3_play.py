from secretpy import Playfair, CryptMachine

def en_de_crypt(cm, s):
	print("Plain text : ",s)
	a=cm.encrypt(s)
	print("Encrypted text : ",a)
	b=cm.decrypt(a)
	print("Decrypted text : ",b)


cm = CryptMachine(Playfair())
alpha = ['m','o','n','a','r','c','h','y','b','c','d','e','f','g','i','k','l','p','q','s','t','u','v','w','x','z'];
cm.set_alphabet(alpha)
plaintext=input("Enter plain text : ")
en_de_crypt(cm,plaintext)