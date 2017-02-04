printf "Enter the path of the file to lock: "
read LOCKFILE
if [ -e ${LOCKFILE} ] && kill -0 `cat ${LOCKFILE}`; then
    echo "already running"
    exit
fi

trap "rm -f ${LOCKFILE}; exit" INT TERM EXIT
echo $$ > ${LOCKFILE}

sleep 1000

rm -f ${LOCKFILE}
