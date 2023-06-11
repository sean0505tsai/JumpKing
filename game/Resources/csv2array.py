import csv

def add_braces(data):
    return "\t{" + data + "},\n"

def write_to_txt(string):
    with open('map.txt', 'w') as file:
        file.write(string)

def main():
    with open('map.csv', 'r') as csvfile:
        reader = csv.reader(csvfile)
        rows = list(reader)
        
        output = "{\n"
        for row in rows:
            row_data = ','.join(row)
            row_data = add_braces(row_data)
            output += row_data
            # if (i % 45) == 0:
            #     output +=  row_data + '\n},\n'
            # elif (i % 45) == 1:
            #     output += '{\n' + row_data + ',\n'
            # else:
            #     output += row_data + ",\n"
        output += '}'
        write_to_txt(output)
        print(output)

if __name__ == '__main__':
    main()
