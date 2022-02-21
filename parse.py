file = input()
headers = ""

with open("templates.h", "r") as f:
	headers = f.read()

file_raw = ""

with open(file, "r") as f:
	file_raw = f.readlines()

line = None
builtin = None

for i, x in enumerate(file_raw):
	if x.strip(" ").strip("\n") == r'#include "templates.h"':
		line = i

	if x.strip(" ").strip("\n") == r'#include <bits/stdc++.h>':
		builtin = i

	if line != None and builtin != None:
		break

if builtin != None:
	headers = headers.replace(r'#include <bits/stdc++.h>', "")

file_raw[line] = headers
file_raw = "".join(file_raw)

with open("raw.cpp", "w") as f:
	f.write(file_raw)