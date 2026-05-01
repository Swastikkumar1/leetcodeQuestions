class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;

        while (i < words.size()) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // 1. Decide how many words fit in the current line
            // Each subsequent word needs at least 1 space (words[j].length() + 1)
            while (j < words.size() && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            string line = "";
            int numWords = j - i;
            int numSpaces = maxWidth - (lineLength - (numWords - 1));

            // 2. Handle Case: Last line or Single-word line (Left Justified)
            if (j == words.size() || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                while (line.length() < maxWidth) line += " ";
            } 
            // 3. Handle Case: Fully Justified
            else {
                int spacesBetween = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = spacesBetween + (extraSpaces-- > 0 ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the next set of words
        }

        return result;
    }
};