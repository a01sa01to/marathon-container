# Update apt
echo "  Updating apt..."
echo "--------------------------"
sudo apt-get update
sudo apt-get upgrade -y
echo "--------------------------"
echo ""

# Update Competitive Terminal
echo "  Downloading Terminal..."
echo "--------------------------"
curl https://github.com/a01sa01to/Competitive-Terminal/releases/download/v1.1.2/competitive-terminal -L -o ./competitive-terminal
chmod +x ./competitive-terminal
echo "--------------------------"
echo ""

# Update ACL
echo "  Downloading ACL..."
echo "--------------------------"
curl https://github.com/atcoder/ac-library/releases/download/v1.4/ac-library.zip -L -o ./ac-library.zip
unzip ac-library.zip -x expander.py -x document_* -o
rm ac-library.zip
echo "--------------------------"

# Show Version
echo "  Version"
echo "--------------------------"
gcc -v
echo "--------------------------"

# Run
./competitive-terminal
echo ""
exit 0