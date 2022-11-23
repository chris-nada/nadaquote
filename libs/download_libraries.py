import requests
import os
import zipfile


# Automatisch Library hinzufügen
def lib_download(name, version, link):
    print("checking", os.path.abspath(name))
    if os.path.exists(name):
        # shutil.rmtree() delete folder
        return
    print("downloading", name, version, "...")
    # wget --no-check-certificate --output-document="$1".zip "$3" # Herunterladen
    name_zip = name + ".zip"
    r = requests.get(link, verify=False)
    with open(name_zip, "wb") as f:
        f.write(r.content)
    # unzip "$1".zip                       # Entpacken
    with zipfile.ZipFile(name_zip, 'r') as temp_zip:
        temp_zip.extractall()
    # rm "$1".zip                          # zip löschen
    os.remove(name_zip)
    # mv "$1"-"$2" "$1"                    # Version aus Ordnernamen entfernen
    os.rename(name + "-" + version, name)


#           | Library, Version, Download-Link
# lib_download nada_assets 1.0 https://gitlab.com/chris_nada/nada_assets/-/archive/1.0/nada_assets-1.0.zip
# lib_download("rang" "3.2" "https://github.com/agauniyal/rang/archive/refs/tags/v3.2.zip")
try:
    lib_download("doctest", "2.4.7", "https://github.com/doctest/doctest/archive/refs/tags/2.4.7.zip")
    lib_download("cereal", "1.3.2", "https://github.com/USCiLab/cereal/archive/refs/tags/v1.3.2.zip")
    lib_download("imgui-sfml", "2.5", "https://github.com/eliasdaler/imgui-sfml/archive/refs/tags/v2.5.zip")
    # cp imconfig-SFML.h imgui/imconfig.h # or: https://www.sanfoundry.com/python-program-append-contents-file-another/ imgui
    lib_download("implot", "0.13", "https://github.com/epezent/implot/archive/refs/tags/v0.13.zip")
    lib_download("imgui", "1.87", "https://github.com/ocornut/imgui/archive/refs/tags/v1.87.zip")
    lib_download("libnada", "main", "https://github.com/chris-nada/libnada/archive/refs/heads/main.zip")
    lib_download("cpr", "1.9.2", "https://github.com/libcpr/cpr/archive/refs/tags/1.9.2.zip")
    lib_download("pugixml", "1.13", "https://github.com/zeux/pugixml/archive/refs/tags/v1.13.zip")
except Exception as e:
    print("Error:", e)


# Interesting:
# https://github.com/jeremydumais/CPP-DateTime-library
