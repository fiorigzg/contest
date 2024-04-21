import json
json_file = input()

res = {}

with open(json_file) as f:
	json_data = json.load(f)

	for row_index in json_data:
		row_type = json_data[row_index]
		row = input().split('_')

		res_row = []

		if row_type == "10":
			for word in row:
				letters_map = []
				for letter in word:
					if letter not in letters_map and letter in "aeiouy":
						letters_map.append(letter)
				if len(letters_map) > 1:
					res_row.append(word)
		elif row_type == "20":
			for word in row:
				if len(word) % 2 == 0:
					res_row.append(word)
		else:
			for word in row:
				res_row.append(word)
		
		res_row.sort(reverse=True)
		res[row_index] = res_row

with open('output.json', 'w') as f:
	f.write(json.dumps(res))
