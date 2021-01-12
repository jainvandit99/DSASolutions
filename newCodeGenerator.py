try:
    # Python 2
    raw_input
except NameError:
    # Python 3 (Python 2's `raw_input` was renamed to `input`)
    raw_input = input

def request_user_input(prompt='> '):
    """Request input from the user and return what has been entered."""
    return raw_input(prompt)

def save(output, filename):
    """Saves the list to a given filename"""
    with open(filename, 'w+') as f:
        f.write(output)

def formatCodeName(codeName):
    formattedCodeName = codeName.replace(' ','\ ')
    return formattedCodeName

def writeContents(codeName):
    formattedCodeName = formatCodeName(codeName)
    template = (
        '#!/bin/bash\n'
        'mkdir {0}\n'
        'touch > {0}/readme.md\n'
        'cat > {0}/{0}.cpp <<EOF\n'
        '//{1}\n'
        '#include<stdc++.h>\n'
        'using namespace std;\n'
        '\n'
        'int main(){{\n'
        '\n'
        '}}\n'
        'EOF\n'
        'git add .\n'
    ).format(formattedCodeName,codeName)
    save(template, 'newCodeGenerator.sh')

def main():
    codeName = request_user_input('Enter name of the problem: ')
    writeContents(codeName)
    

if __name__ == '__main__':
    main()