play_filler () {
	echo PLAYING\ AS\ P$1\ AGAINSTS\ $3\ ON\ MAP\ $4 >> result.log
	for count in {1..5}
	do
		./filler_vm -p$1 ./filler -p$2 ./players/$3.filler -q -f ./maps/map0$4
		cat filler.trace | sed -n '2p' >> result.log
	done
}

rm result.log
touch result.log

players='champely abanlin hcao grati carli superjeannot'

for player in $players
do
	for	map in {0..2}
	do
		play_filler 1 2 $player $map
	#	play_filler 2 1 $player $map
	done
done
