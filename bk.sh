mkdir -p backup
cp *.txt backup/
tar -czf backup.tar.gz backup
echo "Backup complete"
