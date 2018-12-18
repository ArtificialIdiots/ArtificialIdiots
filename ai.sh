#!/bin/sh

while true
do
  read str
  str=${str%'吗？'}
  echo ${str}'！'
done
