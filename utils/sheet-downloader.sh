_dest=$1
if (( $# > 1 )); then
  echo "Usage: [dest folder]"
  exit 1
elif (( $# == 1 )); then
    _dest=$1
else
    _dest=$(pwd)
fi

declare -a _datasheets_urls=("https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf"
                  "https://media.digikey.com/pdf/Data%20Sheets/DFRobot%20PDFs/SEN0193_Web.pdf"
                  "http://www.mantech.co.za/datasheets/products/A000047.pdf")

_download_datasheets() {
    local _dest="$1/datasheets"
    mkdir -p "$_dest"
    for url in "${_datasheets_urls[@]}"; do
        echo $url
        wget -q --random-wait --show-progress --progress=bar --directory-prefix "$_dest" $url
    done
}

if [ -d $_dest ]; then
    _download_datasheets $_dest
else
    echo "\"$_dest\" doesn't exist"
fi
