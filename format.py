import datetime
import os
import shutil

def clean_tags(tags : str) -> str:
	if "," in tags:
		tags = tags.split(",")
	else:
		tags = tags.split(" ")

	tags = list(map(lambda x: x.strip(",").strip(), tags))
	return ", ".join(tags)


file = input()
tags = clean_tags(input())
folder = "archive"
ext = os.path.splitext(file)[1]

file = os.path.abspath(__file__ + "/../" + file)

# assert whether the file exists
assert os.path.exists(file), "File does not exist"

#get date and time in the format of YYYY-MM-DD HH:MM:SS
datestamp = datetime.datetime.now().strftime("date_%Y_%m_%d_time_%H_%M_%S")
file_name = datestamp + ext
new_file = os.path.abspath(f"{__file__}/../{folder}/{file_name}")

shutil.copyfile(file, new_file)
with open("archive.txt", "a") as f:
	info = f"{tags} - {file_name}\n\n"
	f.write(info)