#! /bin/bash

[ -f indulo.dat ] || touch indulo.dat
[ -f aktualis.dat ] || touch aktualis.dat

input=$1
argument=$2

list_process(){
  echo "Currently running processes:"
  echo "PID    State    Process"
  echo "==========================="
  while read -r pid state app; do
    echo "$pid   $state        $app"
  done < aktualis.dat

}

case $input in
  -start)
    if [ -z "$2" ]; then
      echo "Error! Please provide the name of your process!"
      exit 1 
    fi 

    pid=$(shuf -i 1000-9999 -n1)
    echo "$pid S $2" >> aktualis.dat
    echo "Process started succesfully: $2 (PID: $pid)"
  ;;
  -stop)
    if [ -z "$2" ]; then
      echo "Error! Please provide the PID of your process!"
      exit 1 
    fi 
    
    if grep -o -q "$2" aktualis.dat; then
      sed -i "/^$2 /s/S/T/" aktualis.dat
      echo "Process stopped succesfully: $2"
    else
      echo "Error! Process PID not found in the currently running list!"  
    fi

  ;;
  -kill)
    if [ -z "$2" ]; then
      echo "Error! Please provide the PID of your process!"
      exit 1 
    fi 
    if grep -o -q "$2" aktualis.dat; then
      sed -i "/^$2 /d" aktualis.dat
      echo "Process terminated succesfully: $2"
    else
      echo "Error! Process PID not found in the currently running list!"  
    fi
  ;;
  -lista)
    list_process
  ;;
  *) echo "Nem ismert kapcsolo!"
  ;;
esac

exit 0
