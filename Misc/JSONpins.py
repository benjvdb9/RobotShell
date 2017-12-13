import json

PinLU = 0
PinLD = 1
PinRU = 2
PinRD = 3

save_to_json = {'data': {'PinLU': PinLU, 'PinLD': PinLD, 'PinRU': PinRU, 'PinRD': PinRD}};

with open('data.json', 'w') as outfile:
	json.dump(save_to_json, outfile, indent=4)
	
outfile.close()
