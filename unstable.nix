let
  unstableTgz = builtins.fetchTarball {
    # Descriptive name to make the store path easier to identify
    name = "nixos-unstable-2020-09-09";
    # Be sure to update the above if you update the archive
    url = https://github.com/nixos/nixpkgs-channels/archive/daaa0e33505082716beb52efefe3064f0332b521.tar.gz;
    sha256 = "15vprzpbllp9hy5md36ch1llzhxhd44d291kawcslgrzibw51f95";
  };
in
import unstableTgz {}
